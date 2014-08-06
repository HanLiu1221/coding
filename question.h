
namespace CODE
{
	struct Data
	{
		int start_time;
		int end_time;
		int value;
	}
	class DataProcess
	{
		public:
			vector<Data> datum;
		public:
			int FindMaximumValue();
	}
}