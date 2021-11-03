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

void kp::DateTime::setData(kp::DTData* dtdata)
{
	*m_data = *dtdata;
}

kp::DTData* kp::DateTime::getData()
{
	return m_data;
}

void kp::DateTime::addToData(kp::DTData* dtdata)
{
}

void kp::DateTime::subtractFromData(kp::DTData* dtdata)
{
}

kp::DateTime::~DateTime()
{
	delete m_data;
}