class System
{
	public:
		System(const System&) = delete;
		static System& Get()
		{
			static System instance;
			return instance;
		}
		static int Init(){return Get().InitInternal();}
	private:
		System(){};
		int InitInternal()
		{
			std::cout << "[INFO]: Program started" << std::endl;
			std::cout << "[INFO]: Running with cpp version: " << "c++" << __cplusplus << std::endl;	
		return 0;
		}
};
