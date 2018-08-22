#ifndef ENGINE_COMMANDQUEUE_HPP
#define ENGINE_COMMANDQUEUE_HPP

#include <GameEngine/Components/Command.hpp>

#include <queue>


class CommandQueue
{
	public:
		void						push(const Command& command);
		Command						pop();
		bool						isEmpty() const;

		
	private:
		std::queue<Command>			mQueue;
};

#endif // ENGINE_COMMANDQUEUE_HPP
