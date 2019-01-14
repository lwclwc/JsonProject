#include "var.hpp"

using namespace jsonProject;
int main()
{
    Var v = Json::OBJECT;
    Var z = Json::OBJECT;
	Var k =Json::ARRAY;

    v.push("name", "test")
	.push("version", 11);
	//.push("descriptors", "")
	//.push("main", "index.js")
	//.push("scripts", z
	//.push("os", "Linux")
	//.push("path", "nodejs"))
	//.push("authors", k
	//.push("MongoDB")
	//.push("wow"));

    cout << v.json().c_str() << endl;
    return 0;
}