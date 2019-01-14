#include "json.hpp"
#include "jsonType.hpp"

#pragma once

namespace jsonProject
{
    shared_ptr<Json> Json::push(shared_ptr<Json> e)
    {
        (dynamic_cast<JsonArray*>(this))->push(e);
		return shared_ptr<Json> (this);
    }

	shared_ptr<Json> Json::push(const string& name, shared_ptr<Json> v)
    {
        (dynamic_cast<JsonObject*>(this))->push(name, v);
		return shared_ptr<Json> (this);
    }

    shared_ptr<Json> Json::operator[](string key)
    {
        return shared_ptr<Json>();
    }
}