#include"cocos2d.h"
#include"SimpleAudioEngine.h"
#include"SceneManger.h"
#include"network/SocketIO.h"
USING_NS_CC;
using namespace cocos2d::network;
using namespace CocosDenshion;
class OpenLayer :public Layer,public SocketIO::SIODelegate
{
public:
	CREATE_FUNC(OpenLayer);
	virtual bool init();
	void menuCallBack(Ref *psender);
	void updateTimesPerSecond(float);
	void httpRequest(const char*param, int action);
	string getLocalAddress();
public:
	SceneManger *tsm;
	static string localIpAddress;
private:
	Menu *menu;
	int action;
	Label *label4;
	Label *label2;

	virtual void onConnect(cocos2d::network::SIOClient* client);
	virtual void onMessage(cocos2d::network::SIOClient* client, const std::string& data);
	virtual void onClose(cocos2d::network::SIOClient* client);
	virtual void onError(cocos2d::network::SIOClient* client, const std::string& data);

	//void findAllCallBack(cocos2d::network::SIOClient *client, const std::string& data);
	void createCallBack(cocos2d::network::SIOClient *client, const std::string& data);
	void callConnect(cocos2d::network::SIOClient *client, const std::string& data);

	SIOClient *_sioClient;

};