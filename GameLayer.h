#include"cocos2d.h"
#include"SceneManger.h"
#include"network/SocketIO.h"
using namespace cocos2d::network;
USING_NS_CC;
#pragma once
class GameLayer :public Layer, public SocketIO::SIODelegate
{
public:
	CREATE_FUNC(GameLayer);
	virtual bool init();
	void menuCallBack_Start(Ref *pSender);
	void startGame();
	Sprite *setBackground1(const string&,int);
	Sprite *setBackground2(const string&, int);
	virtual void onConnect(cocos2d::network::SIOClient* client);
	virtual void onMessage(cocos2d::network::SIOClient* client, const std::string& data);
	virtual void onClose(cocos2d::network::SIOClient* client);
	virtual void onError(cocos2d::network::SIOClient* client, const std::string& data);
	void findAllCallBack(cocos2d::network::SIOClient *client, const std::string& data);
	void farDisconnect(cocos2d::network::SIOClient *client, const std::string& data);
	void callConnect(cocos2d::network::SIOClient *client, const std::string& data);
public:
	SceneManger *tsm;
	Menu *menu;
	SIOClient *_sioClient;
	bool _connected;
	Label *label4;
	static string farIpAddress;
};