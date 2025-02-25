#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2022/10/25 0:27:04

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
#ifndef _INFO_CONTROLLER_
#define _INFO_CONTROLLER_

#include "domain/query/info-inspectionSave/InfoQuery.h"
#include "domain/vo/info-inspectionSave/InfoVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class InfoController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(InfoController);

public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryInfo) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("info.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(InfoListPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述

		API_DEF_ADD_QUERY_PARAMS(UInt32, "id", ZH_WORDS_GETTER("Info.field.id"), 1, true);

		//体检人员
		API_DEF_ADD_QUERY_PARAMS(UInt32, "personId", ZH_WORDS_GETTER("Info.field.personId"), 1, true);

		//总检医生
		API_DEF_ADD_QUERY_PARAMS(String, "inspectionDoctor", ZH_WORDS_GETTER("Info.field.inspectionDoctor"), "LIHUA", false);

		//总检日期
		API_DEF_ADD_QUERY_PARAMS(String, "inspectionDate", ZH_WORDS_GETTER("Info.field.inspectionDate"), "LI HUA", true);

		//医学建议
		API_DEF_ADD_QUERY_PARAMS(String, "medicalAdvice", ZH_WORDS_GETTER("Info.field.medicalAdvice"), "LI HUA", true);

		//处理意见
		API_DEF_ADD_QUERY_PARAMS(String, "handleOpinion", ZH_WORDS_GETTER("Info.field.handleOpinion"), "LI HUA", true);

		
	}
	//定义分页查询单页列表接口
	ENDPOINT(API_M_GET, "/info/save-info-inspect", queryInfo, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(iq, InfoQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryInfo(iq));
	}

private:
	InfoListPageJsonVO::Wrapper execQueryInfo(const InfoQuery::Wrapper& query);

};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_