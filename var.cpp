#include "var.hpp"

namespace jsonProject
{
	Var::Var(int i)
	{
		m_data = shared_ptr<JsonInt>(new JsonInt(i)); 
	}

	Var::Var(double i)
	{
		m_data = shared_ptr<JsonDouble>(new JsonDouble(i));
	}

	Var::Var(bool i)
	{ 
		m_data = shared_ptr<JsonBool>(new JsonBool(i));
	}

	Var::Var(const char *i)
	{
		m_data = shared_ptr<JsonString>(new JsonString(i)); 
	}

	Var::Var(const std::string &i)
	{
		m_data = shared_ptr<JsonString>(new JsonString(i)); 
	}

	Var::Var(Json::Type t)
	{
		switch (t)
		{
		case Json::BOOL:
			m_data = shared_ptr<JsonBool>(new JsonBool(false));
			break;
		case Json::ARRAY:
			m_data = shared_ptr<JsonArray>(new JsonArray());
			break;
		case Json::OBJECT:
			m_data = shared_ptr<JsonObject>(new JsonObject());
			break;
		case Json::INT:
			m_data = shared_ptr<JsonInt>(new JsonInt(0));
			break;
		case Json::DOUBLE:
			m_data = shared_ptr<JsonDouble>(new JsonDouble(0.0));
			break;
		case Json::STRING:
			m_data = shared_ptr<JsonString>(new JsonString(""));
			break;
		default:
			break;
		}
	}

	Var& Var::push(const std::string& name, const Var& v)
	{
		m_data->push(name, v.m_data);
		return *this;
	}

	Var& Var::push(const Var& v)
	{
		m_data->push(v.m_data);
		return *this;
	}

	string Var::json() const
	{
		return m_data->toJson();
	}

	shared_ptr<Json> Var::operator[](std::string key)
	{
		return m_data->operator[](key);
	}
}