#include <iostream>
#include <fstream>
#include "restclient-cpp/restclient.h"
#include <nlohmann/json.hpp>

std::string getpkginfo = "http://localhost:8080/get-pkg_info/"; 
std::string downpkg = "http://localhost:8080/down-pkg/";

int main(int argc, char* argv[])
{
	
	if (argc != 3 || (argc == 3 && argv[1] != "install")) 
	{
		std::cout << "Unexpected arguments" << std::endl;
		return 0;
	}

	RestClient::Response r = RestClient::get(getpkginfo + std::string(argv[2]));

	auto json_response = nlohmann::json::parse(r.body);

	std::string message = json_response["message"];
	if (message != "present") {
		std::cout << message << std::endl;
		return 0;
	}

	std::string name = json_response["name"];
	std::string version = json_response["version"];
	std::string description = json_response["description"];
	auto headerFiles = json_response["headerFiles"];
	auto binFiles = json_response["binFiles"];
	auto srcFiles = json_response["srcFiles"];
	auto debugLibFiles = json_response["debugLibFiles"];
	auto debugBinFiles = json_response["debugBinFiles"];

	std::cout << name << std::endl;
	std::cout << version << std::endl;
	std::cout << description << std::endl;
//-------------------------------------------------------------------------------------------
	std::cout << "fetching header-files " << std::endl;
	std::cout << "totle header-files: " << headerFiles.size() << std::endl;

	for(const std::string& i:headerFiles)
	{	
		std::cout << "fetching " + i << std::endl;
		RestClient::Response h = RestClient::get("downpkg"+i);
		std::ofstream outFile("C:\\baker-client\\header\\"+i, std::ios::binary);
		outFile.write(h.body.c_str(), h.body.size());
		outFile.close();
	}
//-------------------------------------------------------------------------------------------
	std::cout << "fetching src-files " << std::endl;
	std::cout << "totle src-files: " << srcFiles.size() << std::endl;

	for (const std::string& i : srcFiles)
	{
		std::cout << "fetching " + i << std::endl;
		RestClient::Response h = RestClient::get("downpkg" + i);
		std::ofstream outFile("C:\\baker-client\\src\\" + i, std::ios::binary);
		outFile.write(h.body.c_str(), h.body.size());
		outFile.close();
	}

//-------------------------------------------------------------------------------------------

	std::cout << "fetching bin-files " << std::endl;
	std::cout << "totle bin-files: " << binFiles.size() << std::endl;

	for (const std::string& i : binFiles)
	{
		std::cout << "fetching " + i << std::endl;
		RestClient::Response h = RestClient::get("downpkg" + i);
		std::ofstream outFile("C:\\baker-client\\bin\\" + i, std::ios::binary);
		outFile.write(h.body.c_str(), h.body.size());
		outFile.close();
	}

//-------------------------------------------------------------------------------------------

	std::cout << "fetching debug-bin-files " << std::endl;
	std::cout << "totle debug-bin-files: " << debugBinFiles.size() << std::endl;

	for (const std::string& i : debugBinFiles)
	{
		std::string n = i.substr(3);
		std::cout << "fetching " + n << std::endl;
		RestClient::Response h = RestClient::get("downpkg" + i);
		std::ofstream outFile("C:\\baker-client\\debug\\bin\\" + n, std::ios::binary);
		outFile.write(h.body.c_str(), h.body.size());
		outFile.close();
	}

//-------------------------------------------------------------------------------------------

	std::cout << "fetching debug-lib-files " << std::endl;
	std::cout << "totle debug-lib-files: " << debugLibFiles.size() << std::endl;

	for (const std::string& i : debugLibFiles)
	{
		std::string n = i.substr(3);
		std::cout << "fetching " + n << std::endl;
		RestClient::Response h = RestClient::get("downpkg" + i);
		std::ofstream outFile("C:\\baker-client\\debug\\lib\\" + n, std::ios::binary);
		outFile.write(h.body.c_str(), h.body.size());
		outFile.close();
	}

	return 0;
}