#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include "coreMinimal.hpp"

namespace kp
{
	struct DTData
	{
		uint16_t second;
		uint16_t minute;
		uint16_t hour;
		uint16_t day;
		uint16_t month;
		uint16_t year;
	};

	class DateTime
	{
	private:
		void memoryAllocation();
		void initData();
	protected:
		DTData* m_data;
	public:
		DateTime();

		void setData(kp::DTData* dtdata);
		kp::DTData* getData();

		void addToData(kp::DTData* dtdata);
		void subtractFromData(kp::DTData* dtdata);

		~DateTime();
	};
}

#endif // !DATE_TIME_HPP