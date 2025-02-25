/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "LifeHistoryController.h"
#include "../../service/unknownmodulelifehistory/LifeHistoryService.h"


LifeHistoryPageJsonVO::Wrapper LifeHistoryController::execQueryLifeHistory(const LifeHistoryQuery::Wrapper& lhq) {
	// 定义一个Service
	LifeHistoryService service;
	// 查询数据
	auto result = service.listAll(lhq);
	// 响应结果
	auto jvo = LifeHistoryPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
