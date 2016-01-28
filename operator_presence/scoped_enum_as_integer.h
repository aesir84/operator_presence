#pragma once

namespace helpers
{
	template<typename E>
	constexpr auto as_integer(E enumerator)
	{
		return static_cast<std::underlying_type_t<E>>(enumerator);
	}
}
