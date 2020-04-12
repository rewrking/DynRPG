namespace RPG {

	/*! \brief The Map scene.
		\sa RPG::sceneMap
	*/
	class SceneMap {
		public:
			void **vTable;
			AuroraBoard *AuroraBoard1; //!< Not even a little bit implemented...
			AuroraBoard *AuroraBoard2; //!< Not even a little bit implemented...
			bool initialized; //!< Has the map scene been initialized?
	};

static RPG::SceneMap *&sceneMap = (**reinterpret_cast<RPG::SceneMap ***>(0x4CDC1C));

}
