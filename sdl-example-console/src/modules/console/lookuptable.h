#include "commands.h"

class LookupTable
{
	public:
		LookupTable(const LookupTable&) = delete;
		static LookupTable& Get()
		{
			static LookupTable instance;
			return instance;
		}
		static void Init(){return Get().i_Init();}
		static void CallFunction(
				std::string function,
				std::string argument)
		{
			return Get().i_CallFunction(
					function,
					argument);
		}
	public:
		LookupTable(){}
		void i_Init()
		{
			m_table["PrintToConsole"] = PrintToConsole;
			m_table["ptc"] = PrintToConsole;
			m_table["glFunction"] = glFunction;
			m_table["gluFunction"] = gluFunction;
		}
		void i_CallFunction(
				std::string p_function,
				std::string p_argument)
		{
			LookupTable::Init();
			m_table[p_function](p_argument);
		}
	private:
		typedef void(*FunctionPointer)(std::string);
		std::map<std::string, FunctionPointer> m_table;
};
