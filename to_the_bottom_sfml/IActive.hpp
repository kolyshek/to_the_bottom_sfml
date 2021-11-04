#ifndef I_ACTIVE_HPP
#define I_ACTIVE_HPP

namespace kp
{
	class IActive
	{
	protected:
		bool m_active;
	public:
		virtual void setActive(bool active) = 0;
		virtual bool isActive() const = 0;
	};
}

#endif // !I_ACTIVE_HPP