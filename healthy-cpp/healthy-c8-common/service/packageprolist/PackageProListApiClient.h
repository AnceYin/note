#pragma once
#ifndef _PackageProListApiClient_H_
#define _PackageProListApiClient_H_

#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


#include OATPP_CODEGEN_BEGIN(ApiClient)
/**
 * 获取组合项目列表ApiClient定义声明式服务
 */
class PackageProListApiClient : public oatpp::web::client::ApiClient // 2 继承这个类
{

	//  初始化定义
	API_CLIENT_INIT(PackageProListApiClient);

	// 通过ID查询
	API_CALL(API_M_GET, "now-dev-null", queryPackageProList, API_HANDLER_AUTN_HEADER, API_HANDLER_PAGE_PARAME, QUERY(String, keyword), QUERY(String, section));
};

#include OATPP_CODEGEN_END(ApiClient)
#endif
