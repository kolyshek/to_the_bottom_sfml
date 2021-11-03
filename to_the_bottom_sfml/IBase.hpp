#ifndef I_BASE_HPP
#define I_BASE_HPP

namespace kp
{
	class IBase
	{
	protected:
		float m_dT;
	public:
		virtual void render() = 0;
		virtual void update(float dT) = 0;
	};
}

#endif // !I_BASE_HPP