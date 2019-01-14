#pragma once

#include "json.hpp"
#include <unordered_map>
#include <vector>

namespace jsonProject
{
    class JsonInt : public Json
	{
	public:
        virtual ~JsonInt() {};
		JsonInt(int i);

		virtual Json::Type getType() const;
		virtual string toJson() const;

    private:
		int m_data;
	};

	class JsonDouble : public Json 
    {
	public:
        virtual ~JsonDouble(){};
		JsonDouble(double i);

		virtual Json::Type getType() const;
		virtual string toJson() const;

    private:
		double m_data;
	};

	class JsonBool : public Json
	{
	public:
        virtual ~JsonBool() {}
		JsonBool(bool i);

		virtual Json::Type getType() const;
		virtual string toJson() const;

    private:
		bool m_data;
	};

	class JsonString : public Json
	{
	public:
        virtual ~JsonString() {}
		JsonString(const string &i);

		virtual Json::Type getType() const;
		virtual string toJson() const; 

    private:
		string m_data;
	};

	class JsonArray : public Json
	{
	public:
        virtual ~JsonArray() {}
		JsonArray();

		virtual Json::Type getType() const;
		virtual string toJson() const;
		JsonArray& push(shared_ptr<Json> e);

    private:
		vector<shared_ptr<Json> > m_data;
	};

	class JsonObject : public Json
	{
	public:  
        virtual ~JsonObject() {}
		JsonObject();

		virtual Json::Type getType() const;
		virtual string toJson() const;

		JsonObject& push(const string& name, shared_ptr<Json> v);
		shared_ptr<Json> operator[](string key);

	private:
		unordered_map<string, shared_ptr<Json> > m_data;
	};
}