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
	


};

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}