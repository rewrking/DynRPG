.SUFFIXES:
SUFFIXES =
.SUFFIXES: .c .cpp .h .hpp .rc .res .inl .o .d .asm

#==============================================================================
MAKEFLAGS += --no-print-directory
#==============================================================================
# Build platform
PLATFORM?=windows
# Build description (Primarily uses Debug/Release)
BUILD?=Release
_BUILDL := $(shell echo $(BUILD) | tr A-Z a-z)

# The sub-folder containing the target source files
SRC_TARGET?=
ifneq ($(SRC_TARGET),)
	_SRC_TARGET := /$(SRC_TARGET)
endif

# Maximum parallel jobs during build process
MAX_PARALLEL_JOBS?=8

# Dump assembly?
DUMP_ASSEMBLY?=false

# Clean output?
CLEAN_OUTPUT?=true

# Platform specific environment variables
-include env/.all.mk
-include env/.$(_BUILDL).mk
-include env/$(PLATFORM).all.mk
-include env/$(PLATFORM).$(_BUILDL).mk
ifneq ($(SRC_TARGET),)
-include env/$(SRC_TARGET)/.all.mk
-include env/$(SRC_TARGET)/.$(_BUILDL).mk
-include env/$(SRC_TARGET)/$(PLATFORM).all.mk
-include env/$(SRC_TARGET)/$(PLATFORM).$(_BUILDL).mk
endif

#==============================================================================
# File/Folder dependencies for the production build recipe (makeproduction)
PRODUCTION_DEPENDENCIES?=
# Extensions to exclude from production builds
PRODUCTION_EXCLUDE?=
# Folder location (relative or absolute) to place the production build into
PRODUCTION_FOLDER?=build
PRODUCTION_FOLDER_RESOURCES := $(PRODUCTION_FOLDER)

#==============================================================================
# Library directories (separated by spaces)
LIB_DIRS?=
INCLUDE_DIRS?=
# Link libraries (separated by spaces)
LINK_LIBRARIES?=

# Precompiled header filename (no extension)
# This file will be excluded from Rebuild, but if the bin/(build) directory is removed, it will be as well.
PRECOMPILED_HEADER?=

# Build-specific preprocessor macros
BUILD_MACROS?=
# Build-specific compiler flags to be appended to the final build step (with prefix)
BUILD_FLAGS?=

# Build dependencies to copy into the bin/(build) folder - example: openal32.dll
BUILD_DEPENDENCIES?=

# NAME should always be passed as an argument from tasks.json as the root folder name, but uses a fallback of "game.exe"
# This is used for the output filename (game.exe)
NAME?=game.exe

#==============================================================================
# The source file directory
SRC_DIR := src$(_SRC_TARGET)
LIB_DIR := lib

# Project .cpp or .rc files (relative to $(SRC_DIR) directory)
SOURCE_FILES := $(patsubst $(SRC_DIR)/%,%,$(shell find $(SRC_DIR) -name '*.cpp' -o -name '*.c' -o -name '*.cc' -o -name '*.rc'))
# Project subdirectories within $(SRC_DIR)/ that contain source files
PROJECT_DIRS := $(patsubst $(SRC_DIR)/%,%,$(shell find $(SRC_DIR) -mindepth 1 -maxdepth 99 -type d))

# Add prefixes to the above variables
_LIB_DIRS := $(LIB_DIR:%=-L%/) $(LIB_DIRS:%=-L%)
_INCLUDE_DIRS := $(patsubst %,-I%,$(SRC_DIR)/ $(LIB_DIR)/ $(INCLUDE_DIRS))

_BUILD_MACROS := $(BUILD_MACROS:%=-D%)
_LINK_LIBRARIES := $(LINK_LIBRARIES:%=-l%)


#==============================================================================
# Directories & Dependencies
BLD_DIR := bin/$(BUILD)
BLD_DIR := $(BLD_DIR:%/=%)
TARGET := $(BLD_DIR)/$(NAME)
_NAMENOEXT := $(NAME:.exe=)
_NAMENOEXT := $(_NAMENOEXT:.dll=)

_SOURCES_IF_RC := $(if $(filter windows,$(PLATFORM)),$(SOURCE_FILES:.rc=.res),$(SOURCE_FILES:%.rc=))

OBJ_DIR := $(BLD_DIR)/obj$(_SRC_TARGET)
_OBJS := $(_SOURCES_IF_RC:.c=.c.o)
_OBJS := $(_OBJS:.cpp=.cpp.o)
_OBJS := $(_OBJS:.cc=.cc.o)
OBJS := $(_OBJS:%=$(OBJ_DIR)/%)
OBJ_SUBDIRS := $(PROJECT_DIRS:%=$(OBJ_DIR)/%)

DEP_DIR := $(BLD_DIR)/dep$(_SRC_TARGET)
_DEPS := $(_SOURCES_IF_RC)
_DEPS := $(_DEPS:%=%.d)
DEPS := $(_DEPS:%=$(DEP_DIR)/%) $(DEP_DIR)/$(PRECOMPILED_HEADER).d
DEP_SUBDIRS := $(PROJECT_DIRS:%=$(DEP_DIR)/%)

_PCH_HFILE := $(shell find $(SRC_DIR) -name '$(PRECOMPILED_HEADER).hpp' -o -name '$(PRECOMPILED_HEADER).h' -o -name '$(PRECOMPILED_HEADER).hh')
_PCH_HFILE := $(_PCH_HFILE:$(SRC_DIR)/%=%)
_PCH_EXT := $(_PCH_HFILE:$(PRECOMPILED_HEADER).%=%)
_PCH_COMPILER_EXT := gch


_PCH := $(_PCH_HFILE:%=$(OBJ_DIR)/%)
ifneq ($(_PCH),)
	_PCH_GCH := $(_PCH).$(_PCH_COMPILER_EXT)
endif

ifeq ($(DUMP_ASSEMBLY),true)
	ASM_DIR := $(BLD_DIR)/asm$(_SRC_TARGET)
	_ASMS := $(_OBJS:%.res=)
	_ASMS := $(_ASMS:.o=.o.asm)
	ASMS := $(_ASMS:%=$(ASM_DIR)/%)
	ASM_SUBDIRS := $(PROJECT_DIRS:%=$(ASM_DIR)/%)
endif

_DIRECTORIES := $(sort bin $(BLD_DIR) $(OBJ_DIR) $(OBJ_SUBDIRS) $(DEP_DIR) $(DEP_SUBDIRS) $(ASM_DIR) $(ASM_SUBDIRS))

_CLEAN := $(filter true,$(CLEAN_OUTPUT))

# Quiet flag
_Q := $(if $(_CLEAN),@)

#==============================================================================
# Compiler & flags
CC?=g++
RC?=windres.exe
CFLAGS?=-O2 -Wall -fdiagnostics-color=always

CFLAGS_DEPS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
CFLAGS_DEPS_T = -MT $@ -MMD -MP -MF $(DEP_DIR)/.$(TEST_DIR)/$*.Td
PCH_COMPILE = $(CC) $(CFLAGS_DEPS) $(_BUILD_MACROS) $(CFLAGS) $(_INCLUDE_DIRS) -o $@ -c $<
ifneq ($(_PCH),)
	_INCLUDE_PCH := -include $(_PCH)
endif

OBJ_COMPILE = $(CC) $(CFLAGS_DEPS) $(_BUILD_MACROS) $(_INCLUDE_DIRS) $(_INCLUDE_PCH) $(CFLAGS) -o $@ -c $<
OBJ_COMPILE_T = $(CC) $(CFLAGS_DEPS_T) $(_BUILD_MACROS) $(_INCLUDE_DIRS) $(_INCLUDE_PCH) $(CFLAGS) -o $@ -c $<

RC_COMPILE = -$(RC) -J rc -O coff -i $< -o $@
ASM_COMPILE = objdump -d -C -Mintel $< > $@
POST_COMPILE = mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@
POST_COMPILE_T = mv -f $(DEP_DIR)/.$(TEST_DIR)/$*.Td $(DEP_DIR)/.$(TEST_DIR)/$*.d && touch $@

#==============================================================================
# Build Scripts
all:
	@$(MAKE) makepch
	@$(MAKE) -j$(MAX_PARALLEL_JOBS) makebuild
.DELETE_ON_ERROR: all

rebuild: clean all
.PHONY: rebuild

buildprod: all makeproduction
.PHONY: buildprod

#==============================================================================
# Functions
define color_reset
	@tput setaf 4
endef

define comple_with
	$(color_reset)
	$(if $(_CLEAN),@echo $($(2):$(OBJ_DIR)/%=%))
	$(_Q)$(3) && $(4)
endef

MKDIR := $(_Q)mkdir -p

makepch: $(_PCH_GCH)
	@echo > /dev/null
.PHONY: makepch

makebuild: $(TARGET)
	$(color_reset)
	@echo '$(BUILD) build target is up to date.'
.PHONY: makebuild

#==============================================================================
# Build Recipes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%
$(OBJ_DIR)/%.o: $(SRC_DIR)/% $(_PCH_GCH) $(DEP_DIR)/%.d | $(_DIRECTORIES)
	$(call comple_with,@,<,$(OBJ_COMPILE),$(POST_COMPILE))

$(OBJ_DIR)/.$(TEST_DIR)/%.o: $(TEST_DIR)/%
$(OBJ_DIR)/.$(TEST_DIR)/%.o: $(TEST_DIR)/% $(_PCH_GCH) $(DEP_DIR)/.$(TEST_DIR)/%.d | $(_DIRECTORIES)
	$(call comple_with,@,<,$(OBJ_COMPILE_T),$(POST_COMPILE_T))

$(OBJ_DIR)/%.$(_PCH_EXT).$(_PCH_COMPILER_EXT) : $(SRC_DIR)/%.$(_PCH_EXT)
$(OBJ_DIR)/%.$(_PCH_EXT).$(_PCH_COMPILER_EXT) : $(SRC_DIR)/%.$(_PCH_EXT) $(DEP_DIR)/%.d | $(_DIRECTORIES)
	$(call comple_with,@,<,$(PCH_COMPILE),$(POST_COMPILE))

$(OBJ_DIR)/%.res: $(SRC_DIR)/%.rc
$(OBJ_DIR)/%.res: $(SRC_DIR)/%.rc $(DEP_DIR)/%.d | $(_DIRECTORIES)
	$(color_reset)
	$(if $(_CLEAN),@echo $(<:$(OBJ_DIR)/%=%))
	$(_Q)$(RC_COMPILE)

$(ASM_DIR)/%.o.asm: $(OBJ_DIR)/%.o
	$(if $(_CLEAN),,$(color_reset))
	$(_Q)$(ASM_COMPILE)

$(TARGET): $(_PCH_GCH) $(OBJS) $(ASMS) $(TEST_DIR)
	$(color_reset)
	$(if $(_CLEAN),@echo; echo 'Linking: $(TARGET)')
ifeq ($(BUILD_STATIC),true)
	-$(_Q)rm -rf $(BLD_DIR)/lib$(_NAMENOEXT).a
	ar.exe -r -s $(BLD_DIR)/lib$(_NAMENOEXT).a $(OBJS)
else
	-$(_Q)rm -rf $(BLD_DIR)/lib$(_NAMENOEXT).def $(BLD_DIR)/lib$(_NAMENOEXT).a
	$(_Q)$(CC) -shared -Wl,--output-def="$(BLD_DIR)/lib$(_NAMENOEXT).def" -Wl,--out-implib="$(BLD_DIR)/lib$(_NAMENOEXT).a" -Wl,--dll $(_LIB_DIRS) $(OBJS) -o $@ -s $(_LINK_LIBRARIES) $(BUILD_FLAGS)
endif
	$(foreach dep,$(BUILD_DEPENDENCIES),$(shell cp -r $(dep) $(BLD_DIR)))

$(_DIRECTORIES):
	$(if $(_CLEAN),,$(color_reset))
	$(MKDIR) $@

clean:
	$(color_reset)
	$(if $(_CLEAN),@echo 'Cleaning old build files & folders...'; echo)
	$(_Q)$(RM) $(TARGET) $(DEPS) $(OBJS)
.PHONY: clean

#==============================================================================
# Production recipes

rmprod:
	$(color_reset)
	-$(_Q)rm -rf $(PRODUCTION_FOLDER)
.PHONY: rmprod

mkdirprod:
	$(color_reset)
	$(MKDIR) $(PRODUCTION_FOLDER)
.PHONY: mkdirprod

releasetoprod: $(TARGET)
	$(color_reset)
	$(_Q)cp $(TARGET) $(PRODUCTION_FOLDER)
.PHONY: releasetoprod

makeproduction: rmprod mkdirprod releasetoprod
	$(color_reset)
	@echo -n 'Adding dynamic libraries & project dependencies...'
	$(foreach dep,$(PRODUCTION_DEPENDENCIES),$(shell cp -r $(dep) $(PRODUCTION_FOLDER_RESOURCES)))
	$(foreach excl,$(PRODUCTION_EXCLUDE),$(shell find $(PRODUCTION_FOLDER_RESOURCES) -name '$(excl)' -delete))
	@echo ' Done'
.PHONY: makeproduction

#==============================================================================
# Dependency recipes
$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d

include $(wildcard $(DEPS))
