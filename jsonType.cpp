#include "jsonType.hpp"

namespace jsonProject
{
    JsonInt::JsonInt(int i) : m_data(i) 
    {}

	Json::Type JsonInt::getType() const
    { 
        return Type::INT; 
    }

	string JsonInt::toJson() const
	{
		return to_string(static_cast<_LONGLONG>(m_data));
	}

	JsonDouble::JsonDouble(double i) : m_data(i)
    {}

	Json::Type JsonDouble::getType() const
    { 
        return Type::DOUBLE;
    }

	string JsonDouble::toJson() const
	{
		return to_string(static_cast<_LONGLONG>(m_data));
	}

    JsonBool::JsonBool(bool i) : m_data(i) 
    {}

	Json::Type JsonBool::getType() const
    {
            return Type::BOOL;
    }

	string JsonBool::toJson() const
    {
		return m_data ? "true" : "false";
	}

    JsonString::JsonString(const string &i) : m_data(i)
    {}

	Json::Type JsonString::getType() const
    {
            return Type::STRING;
    }

	string JsonString::toJson() const
	{
		return "\"" + m_data + "\"";
	}

    JsonArray::JsonArray() : m_data()
    {}

	Json::Type JsonArray::getType() const
    { 
        return Type::ARRAY;
    }

	string JsonArray::toJson() const
	{
		if (m_data.empty())
        {
			return "[]";
        }

		string json = "[";
		vector<shared_ptr<Json> >::const_iterator it = m_data.begin();
		for (; it != m_data.end(); ++it)
		{
			json += (*it)->toJson();
			if (*it != m_data.back())
            {
				json += ",";
            }
		}

		return json + "]";
	}

	JsonArray& JsonArray::push(shared_ptr<Json> e)
	{
		m_data.push_back(e);
		return *this;
	}

    JsonObject::JsonObject() : m_data()
    {}

	Json::Type JsonObject::getType() const 
    { 
        return OBJECT;
    }

	string JsonObject::toJson() const
	{
		string json = "{";
		unordered_map<string, shared_ptr<Json> >::const_iterator it = m_data.begin();
		for (; it != m_data.end();)
		{
			const pair<string, shared_ptr<Json> >& e = *it;
			json += ("\"" + e.first + "\"");
			json += ":";
			json += e.second->toJson();

			if (++it != m_data.end())
            {
				json += ",";
            }
		}

		return json + "}";
	}

	JsonObject& JsonObject::push(const string& name, shared_ptr<Json> v)
	{
		m_data[name] = v;
		return *this;
	}

	shared_ptr<Json> JsonObject::operator[](string key)
	{
		return m_data[key];
	}
}