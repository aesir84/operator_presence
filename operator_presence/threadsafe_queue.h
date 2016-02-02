#pragma once

namespace helpers
{
	template<typename T>
	class threadsafe_queue
	{
	public:
		threadsafe_queue()
		{ }

		threadsafe_queue(threadsafe_queue const & other)
		{
			std::lock_guard<std::mutex> mutex_lock(other.m_mutex);
			m_data_queue = other.m_data_queue;
		}

		threadsafe_queue & operator=(threadsafe_queue const & rhs) = delete;

		void push(T new_value)
		{
			std::lock_guard<std::mutex> mutex_lock(m_mutex);

			m_data_queue.push(new_value);
			m_data_ready.notify_one();
		}

		std::shared_ptr<T> wait_and_pop()
		{
			std::unique_lock<std::mutex> mutex_lock(m_mutex);

			m_data_ready.wait(mutex_lock, [this] { return !m_data_queue.empty(); });

			std::shared_ptr<T> result(std::make_shared<T>(m_data_queue.front()));
			m_data_queue.pop();

			return result;
		}

		void wait_and_pop(T & value)
		{
			std::unique_lock<std::mutex> mutex_lock(m_mutex);

			m_data_ready.wait(mutex_lock, [this] { return !m_data_queue.empty(); });

			value = m_data_queue.front();
			m_data_queue.pop();
		}

	private:
		std::queue<T> m_data_queue;

		std::mutex m_mutex;
		std::condition_variable m_data_ready;

	};
}

