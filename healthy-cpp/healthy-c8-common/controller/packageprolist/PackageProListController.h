#pragma once
#ifndef _PackageProList_Controller_
#define _PackageProList_Controller_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/packageprolist/PackageProListQuery.h"
#include "domain/dto/packageprolist/PackageProListDTO.h"
#include "domain/vo/packageprolist/PackageProListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class PackageProListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PackageProListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口2描述
	ENDPOINT_INFO(queryPackageProList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("packageprolist.query-packageprolist.summary"), PackageProListPageJsonVO::Wrapper);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("packageprolist.field.keyword"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "section", ZH_WORDS_GETTER("packageprolist.field.section"), "", false);

	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_QUERY_AUTH(API_M_GET, "/common/query-packageprolist", queryPackageProList, PackageProListQuery, execQueryPackageProList(query, authObject->getPayload()));
private:
	// 3.3 测试声明式服务调用2
	PackageProListPageJsonVO::Wrapper execQueryPackageProList(const PackageProListQuery::Wrapper& query, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif