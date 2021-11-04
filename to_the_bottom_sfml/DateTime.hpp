#ifndef DATE_TIME_HPP
#define DATE_TIME_HPP

#include "coreMinimal.hpp"

namespace kp
{
	struct DTData
	{
		int16_t second = 0;
		int16_t minute = 0;
		int16_t hour = 0;
		int16_t day = 0;
		int16_t month = 0;
		int16_t year = 0;
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
		DateTime(const kp::DateTime& copy);

		void setData(kp::DTData* dtdata);
		const kp::DTData* getData() const;

		void addDates(kp::DTData* dtdata, uint16_t dayInMonth = 29);
		void subtractDates(kp::DTData* dtdata, uint16_t dayInMonth = 29);

		static kp::DTData* generateData();

		friend std::ostream& operator<<(std::ostream& out, const DateTime& dateTime);

		~DateTime();
	};
}

#endif // !DATE_TIME_HPP