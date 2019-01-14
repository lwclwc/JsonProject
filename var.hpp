#pragma once

#include "jsonType.hpp"

namespace jsonProject
{
    class Var
	{
	public:	
		~Var() {};
		Var(int i);
		Var(double i);
		Var(bool i);
		Var(const char *i);
		Var(const std::string &i);
		Var(Json::Type t);

		Var& push(const string& name, const Var& v);
		Var& push(const Var& v);

		string json() const;

		shared_ptr<Json> operator[](string key);

	private:
		shared_ptr<Json> m_data;
	};
}