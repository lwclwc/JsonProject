#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace jsonProject
{
    using namespace std;

	class Json
	{
    public:
        // json 支持的类型
        enum Type
        {
            INT, 
            BOOL, 
            DOUBLE, 
            STRING, 
            ARRAY, 
            OBJECT
        };
    
	public:
		virtual ~Json() {}
        Json() {}
	
		// 转化为json数据格式
		virtual string toJson() const = 0;

		// 获取Json数据类型
		virtual Json::Type getType() const = 0;

		// 添加json数据
		shared_ptr<Json> push(shared_ptr<Json> e);
		shared_ptr<Json> push(const string& name, shared_ptr<Json> v);
        shared_ptr<Json> operator[](string key);
	};
}