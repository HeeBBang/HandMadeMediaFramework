#include <boost/asio/io_service.hpp>
#include <boost/thread/thread_pool.hpp>
#include <boost/thread/thread.hpp>

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
	/// ��� ���� ������Ʈ�鿡�� �̺�Ʈ ����
	/// 
	/// </summary>
	void dispatchEvent();

	/// <summary>
	/// �̺�Ʈ ���� ������Ʈ �߰�
	/// </summary>
	void addEventListener();


private:
	boost::asio::io_service event_loop;
	//boost::asio::io_service::work work(event_loop);

	boost::basic_thread_pool thread_pool;
	boost::thread main_loop;
	bool operation;


	/// <summary>
	/// Event Manager�� Event Loop ����
	/// </summary>
	void start(void);

	/// <summary>
	/// Event Manager�� Event Loop ����
	/// </summary>
	void stop(void);


	


};

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}