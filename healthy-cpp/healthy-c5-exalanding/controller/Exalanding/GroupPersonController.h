#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
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
#ifndef _GROUPPERSON_CONTROLLER_
#define _GROUPPERSON_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/Exalanding/GroupPersonDTO.h"
#include "domain/vo/Exalanding/GroupPersonVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 团检人员控制器，演示基础接口的使用
 */
class GroupPersonController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(GroupPersonController);
	// 3 定义接口
public:

	// 定义新增接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("exalanding.post.insertInformation"), addGroupPerson, Uint64JsonVO::Wrapper);
	// 定义新增接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "Exalanding/add-groupPerson", addGroupPerson, BODY_DTO(GroupPersonDTO::Wrapper, dto), execAddGroupPerson(dto));
private:
	// 演示新增数据
	Uint64JsonVO::Wrapper execAddGroupPerson(const GroupPersonDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _GROUPPERSON_CONTROLLER_