#pragma once

namespace helpers
{
	/// \brief A class to manage resources acquisition and an optional freeing.
	///
	/// The idea of this class is taken from Andrei Alexandrescu presentation at CH9:
	/// http://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Andrei-Alexandrescu-Systematic-Error-Handling-in-C
	/// It is a revised version of his earlier work, which can be found here:
	/// http://www.drdobbs.com/cpp/generic-change-the-way-you-write-excepti/184403758
	/// The point is to use the RAII idiom to be able to free the resources when the scope is exited.
	/// The key point though is the ability to cancel the resources freeing.
	/// Basically, this means that it is possible to rollback any changes if, for example, an exception is thrown.
	/// C++11 made this class very handy to use.
	///
	template <class F>
	class scope_guard
	{
	public:
		scope_guard(F func)
			: m_func(std::move(func))
			, m_active(true)
		{ }

		scope_guard(scope_guard && rhs)
			: m_func(std::move(rhs.m_func))
			, m_active(rhs.m_active)
		{
			rhs.dismiss(); // tell the other object, that it can forget about its duties, because our object will do all the work now
		}

		/// \brief A destructor.
		///
		/// The destructor uses the m_active flag to decide whether
		/// to it is needed to release the resource or not.
		///
		~scope_guard()
		{
			if (m_active)
			{
				m_func();
			}
		}

		scope_guard() = delete;
		scope_guard(scope_guard const &) = delete;
		scope_guard& operator=(scope_guard const &) = delete;

		/// \brief A method to clear the release flag.
		///
		/// The method simply sets m_active to false, thus, telling
		/// the object to cancel the resource freeing during destruction.
		///
		void dismiss()
		{
			m_active = false;
		}

	private:
		/// \brief A function to free the resources.
		///
		/// This function is actually a closure created by a lambda expression.
		/// Therefore, it contains all the required data to be released.
		/// \sa ScopeGuard()
		///
		F m_func;

		/// \brief A release flag.
		///
		/// The flag shows whether the resource is to be released or not.
		/// \sa dismiss()
		/// \sa ~ScopeGuard()
		///
		bool m_active;

	};

	/// \brief A helping function to construct a ScopeGuard object
	///
	/// \param A lambda expression.
	/// \return A constructed ScopeGuard object.
	///
	template <class F>
	scope_guard<F> guard_scope(F func)
	{
		return scope_guard<F>(std::move(func));
	}
}
