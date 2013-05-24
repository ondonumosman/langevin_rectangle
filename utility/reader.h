#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>


class Reader{

public:
	Reader(const char* inputfile, const char* folder){
		
		directory = folder;
		copy_name<<folder<<"/applied_parameters.in";
		
		inputstream.open(inputfile);
		if(inputstream.is_open()){
			std::cout<<"parameter file is opened\n";
			this->parse();
		}
		else {
			std::cout<<"Unable to open parameter file\n";
			exit(0);
		}
	}

	void parse(){
	
	std::ofstream copy_file(copy_name.str().c_str(),std::ios::out);	
	
	if(copy_file.is_open()){
		std::cout<<"solution directory exists\n";
	}
	else{
		std::cout <<"solution directory "<<directory<<" does not exist\n";
		exit(0);
	}
	
	
	std::string line;
	while(!inputstream.eof()){
			getline(inputstream,line);
			//WE TAKE A COPY OF THE PARAMETER FILE
			copy_file<<line<<std::endl;
			if(!line.empty()) all_lines.push_back(line); //get all non empty lines
	}
	copy_file.close();
	std::string val;
	
	for(int ii=0;ii<(int)all_lines.size(); ii++ ){ //iterate over lines
		
			if(all_lines.at(ii).substr(0,1)!="#"){ // # marks a comment, so omit lines starting with #
				size_t pst1, pst2;
				int end = all_lines.at(ii).size(); 
				pst1=all_lines.at(ii).find_first_of(" "); //find the positions of first and second spaces
				pst2=all_lines.at(ii).find_last_of(" ");  // in "parameter = value" construct
			
				val = all_lines.at(ii).substr(pst2+1,end-pst2-1); 
				parval[all_lines.at(ii).substr(0,pst1)] = val; //strtod(val.c_str(),NULL);
			}
		}
	
	}

	//GET CHAR
	const char* get_char(std::string key){
		
		std::map<std::string,std::string>::iterator it = parval.find(key);
		if (it==parval.end()){
			std::cout<<"parameter key error while reading "<<key<<"\n";
			return 0;
			}
		else {		
			return (it->second).c_str();
			}
		}
	
	//GET DOUBLE
	double get_double(std::string key){
		
		std::map<std::string,std::string>::iterator it = parval.find(key);
		if (it==parval.end()){
			std::cout<<"parameter key error while reading "<<key<<"\n";
			return 0;
			}
		else {		
			return strtod((it->second).c_str(),NULL);
			}
		}
	
	//GET BOOLEAN	
	bool get_bool(std::string key){
		
		std::map<std::string,std::string>::iterator it = parval.find(key);
		if (it==parval.end()){
			std::cout<<"parameter key error while reading "<<key<<"\n";
			return 0;
			}
		else {
			if(it->second == "false"){ return false;}		
			else if(it->second == "true"){ return true;}		
			else { 
				std::cout<<"this is not a boolean\n";
				return 0;}
			}
		}
	
	//GET INT	
	int get_int(std::string key){
		
		std::map<std::string,std::string>::iterator it = parval.find(key);
		if (it==parval.end()){
			std::cout<<"parameter key error while reading "<<key<<"\n";
			return 0;
			}
		else {		
			return atoi((it->second).c_str());
			}
		}
	
	const char* get_directory(){ return directory;}
protected:
std::stringstream copy_name;
std::ifstream inputstream;
std::vector<std::string> all_lines;
std::map<std::string, std::string> parval;
const char* directory;
};
