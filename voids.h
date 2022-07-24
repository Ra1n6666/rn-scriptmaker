#pragma once
#include "include.h"

using namespace std;

void start();
void settings();
void header();
void input();
void makemanifest(string location, int server);
void makefile(string location, int type, string command, string message);
void closer();

void closer()
{
	system("cls");
	header();
	cout << "Thank you for using Ra1n's Script Maker.\n";
	cout << "Please do not close the app.";
	Sleep(3000);
}

void makemanifest(string location2, int server)
{
	if (server == 0)
	{
		ofstream outfile(location2 + "\\fxmanifest.lua");
		outfile << "----------------------------\n--Made By <Ra1n6666/>#6666--\n----------------------------\nfx_version 'cerulean'\n\ngames { 'gta5' }\n\nauthor '<Ra1n6666/>#6666'\ndescription 'Made with Ra1n Script Maker'\nversion '1.0.0'\n\nclient_scripts {\n  'client/rn-c.lua'\n}\n\nlua54 'yes'";
		outfile.close();
		closer();
	}
	else if (server == 1)
	{
		ofstream outfile(location2 + "\\fxmanifest.lua");
		outfile << "----------------------------\n--Made By <Ra1n6666/>#6666--\n----------------------------\nfx_version 'cerulean'\n\ngames { 'gta5' }\n\nauthor '<Ra1n6666/>#6666'\ndescription 'Made with Ra1n Script Maker'\nversion '1.0.0'\n\nclient_scripts {\n  'client/rn-c.lua'\n}\nserver_scripts{\n    'server/rn-s.lua'\n }\n\nlua54 'yes'";
		outfile.close();
		closer();
	}
}

void makefile(string location, int type, string command, string message)
{
	if (type == 1)
	{
		makemanifest(location, 0);
		ofstream outfile(location + "\\rn-c.lua");
		outfile << "--Made with Ra1n's Script Maker\nRegisterCommand('" << command << "', function()\n	print('" << message << "')\nend)";
		outfile.close();
	}
}

void settings()
{
	system("color 4");
}

void header()
{
	cout << R"(
  _____  _   _        _____  _____ _____  _____ _____ _______ 
 |  __ \| \ | |      / ____|/ ____|  __ \|_   _|  __ \__   __|
 | |__) |  \| |_____| (___ | |    | |__) | | | | |__) | | |   
 |  _  /| . ` |______\___ \| |    |  _  /  | | |  ___/  | |   
 | | \ \| |\  |      ____) | |____| | \ \ _| |_| |      | |   
 |_|  \_\_| \_|   _ |_____/_\_____|_|  \_\_____|_|      |_|   
 |  \/  |   /\   | |/ /  ____|  __ \                          
 | \  / |  /  \  | ' /| |__  | |__) |                         
 | |\/| | / /\ \ |  < |  __| |  _  /                          
 | |  | |/ ____ \| . \| |____| | \ \                          
 |_|  |_/_/    \_\_|\_\______|_|  \_\                         
		)";
	cout << "\n\n";
}

void input()
{
	cout << "Please choose the script you want to make.\n";
	cout << "[1] Print Command.\n";
	cout << "More soon..\n";
	cout << "Input: ";
	string script;
	cin >> script;
	if (script == "1" or script == "2")
	{
		if (script == "1")
			script = "Print Command";
		cout << "You have successfully chosen " << script << ".\n";
		cout << "Script Location: ";
		string location;
		cin >> location;
		cout << "Command: ";
		string command;
		cin >> command;
		cout << "Message to print: ";
		string mtop;
		cin >> mtop;
		makefile(location, 1, command, mtop);
	}
	else
	{
		cout << "This is not a valid option.";
		Sleep(1000);
		start();
	};
}

void start()
{
	system("cls");
	header();
	input();
}