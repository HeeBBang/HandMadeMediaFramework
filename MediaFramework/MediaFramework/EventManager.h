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
	


};

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}