#include <boost/asio/io_service.hpp>
#include <boost/thread/thread_pool.hpp>
#include <boost/thread/thread.hpp>
#include <boost/smart_ptr.hpp>

class EventManager
{
public:
	EventManager();
	~EventManager();


	/// <summary>
	/// 
	/// </summary> 
	/// <param name=""></param>
	/// <returns></returns>
	/// 
	void PostTask();

	/// <summary>
	/// 모든 하위 컴포넌트들에게 이벤트 전달
	/// 
	/// </summary>
	void dispatchEvent();

	/// <summary>
	/// 이벤트 하위 컴포넌트 추가
	/// </summary>
	void addEventListener();


private:
	boost::asio::io_service event_loop;
	
	boost::basic_thread_pool thread_pool;

	boost::scoped_ptr<boost::thread> main_loop;
	

	bool operation;


	/// <summary>
	/// Event Manager의 Event Loop 시작
	/// </summary>
	void start(void);

	/// <summary>
	/// Event Manager의 Event Loop 종료
	/// </summary>
	void stop(void);


	


};