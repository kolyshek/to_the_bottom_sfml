#include "DateTime.hpp"

void kp::DateTime::memoryAllocation()
{
	m_data = new kp::DTData;
}

void kp::DateTime::initData()
{
	m_data->second = 0;
	m_data->minute = 0;
	m_data->hour = 0;
	m_data->day = 0;
	m_data->month = 0;
	m_data->year = 0;
}

kp::DateTime::DateTime()
{
	memoryAllocation();
	initData();
}

kp::DateTime::DateTime(const kp::DateTime& copy)
{
	m_data->second = copy.m_data->second;
	m_data->minute = copy.m_data->minute;
	m_data->hour = copy.m_data->hour;
	m_data->day = copy.m_data->day;
	m_data->month = copy.m_data->month;
	m_data->year = copy.m_data->year;
}

void kp::DateTime::setData(kp::DTData* dtdata)
{
	*m_data = *dtdata;
}

const kp::DTData* kp::DateTime::getData() const
{
	return m_data;
}

void kp::DateTime::addDates(kp::DTData* dtdata, uint16_t dayInMonth)
{
	m_data->second += dtdata->second;
	m_data->minute += dtdata->minute;
	m_data->hour += dtdata->hour;
	m_data->day += dtdata->day;
	m_data->month += dtdata->month;
	m_data->year += dtdata->year;

	if (m_data->second >= 60)
	{
		m_data->second = m_data->second - 60;
		m_data->minute += 1;
	}
	if (m_data->minute >= 60)
	{
		m_data->minute = m_data->minute - 60;
		m_data->hour += 1;
	}
	if (m_data->hour >= 24)
	{
		m_data->hour = m_data->hour - 24;
		m_data->day += 1;
	}
	if (m_data->day >= dayInMonth)
	{
		m_data->day = m_data->day - dayInMonth;
		m_data->month += 1;
	}
	if (m_data->month >= 12)
	{
		m_data->month = m_data->month - 12;
		m_data->year += 1;
	}
}

void kp::DateTime::subtractDates(kp::DTData* dtdata, uint16_t dayInMonth)
{
	m_data->second -= dtdata->second;
	m_data->minute -= dtdata->minute;
	m_data->hour -= dtdata->hour;
	m_data->day -= dtdata->day;
	m_data->month -= dtdata->month;
	m_data->year -= dtdata->year;

	if (m_data->second < 0)
	{
		m_data->second = 60 + m_data->second;
		m_data->minute -= 1;
	}
	if (m_data->minute < 0)
	{
		m_data->minute = 60 + m_data->minute;
		m_data->hour -= 1;
	}
	if (m_data->hour < 0)
	{
		m_data->hour = 24 + m_data->hour;
		m_data->day -= 1;
	}
	if (m_data->day < 0)
	{
		m_data->day = dayInMonth + m_data->day;
		m_data->month -= 1;
	}
	if (m_data->month < 0)
	{
		m_data->month = 12 + m_data->month;
		m_data->year -= 1;
	}

	if (m_data->second < 0)
		m_data->second = 0;
	if (m_data->minute < 0)
		m_data->minute = 0;
	if (m_data->hour < 0)
		m_data->hour = 0;
	if (m_data->day < 0)
		m_data->day = 0;
	if (m_data->month < 0)
		m_data->month = 0;
	if (m_data->year < 0)
		m_data->year = 0;
}

kp::DTData* kp::DateTime::generateData()
{
	kp::DTData* data = new kp::DTData;

	data->second = 1 + rand() % 60;
	data->minute = 1 + rand() % 60;
	data->hour = 1 + rand() % 20;
	data->day = 1 + rand() % 31;
	data->month = 1 + rand() % 12;
	data->year = 1991 + rand() % 31;

	return data;
}

kp::DateTime::~DateTime()
{
	delete m_data;
}

std::ostream& kp::operator<<(std::ostream& out, const DateTime& dateTime)
{
	out << "[ " << dateTime.m_data->day << "-" << dateTime.m_data->month << "-" << dateTime.m_data->year << " | "
		<< dateTime.m_data->hour << ":" << dateTime.m_data->minute << ":" << dateTime.m_data->second << " ]" << "\n";

	return out;
}