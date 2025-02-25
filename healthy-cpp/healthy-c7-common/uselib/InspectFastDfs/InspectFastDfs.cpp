/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/24 23:29:51

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0



 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/



#include "stdafx.h"
#include <iostream>
#include "InspectFastDfs.h"
// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

string test = "";
string InspectFastDfs::InspectDfsWithConf(string fileName)
{
	//	// 定义一个Nacos客户端对象，用于获取配置
	//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	//#ifdef LINUX
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	//	// 从Nacos配置中心获取FastDFS客户端配置数据
	//	std::string config = ns.getConfigText("client.conf");
	//	// 定义客户端对象
	//	FastDfsClient client(config, false);
	//#else
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//	// 从配置中获取FastDFS客户端配置数据
	//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//	std::string ip = ipPort.substr(0, ipPort.find(":"));
	//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//	// 定义客户端对象
	//	FastDfsClient client(ip, port);
	//#endif
	//	// 设置url前缀
	//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";

		// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	cout << downloadUrl << endl;
	test = downloadUrl;
	return downloadUrl;
}

