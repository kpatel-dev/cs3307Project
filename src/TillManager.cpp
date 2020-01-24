#include <iostream>
#include <iomanip>
#include "TillManager.h"
/**
 * Till Manager class
 * 
 * This class allows you to create instances of a Till and has several 
 * funtions to be able to manipulate the data, such as getters, setters and deletes 
 */

using namespace std;  

 /**
  * Till Manager instance
  * Starts a instance as NULL allowing it to be start getting written to
  */ 
TillManager * TillManager:: _instance=NULL; 


 /**
   * Till Manager constructor
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param TillManager& other
   */
TillManager::TillManager(TillManager& other){
    ;
}

 /**
   * Till Manager constructor
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param TillManager other 
   */
TillManager& TillManager:: operator= (TillManager other){
    ;
}
 /**
   * Till Manager protected constructor
   * This is a singleton implementation (protected constructor) used to clear an instance of the Tillmanager, removes all inside
   */
TillManager::TillManager(){
    this->tills.clear();
}

 /**
   * Till Manager constructor
   * If the Till manager doesnt exist then it creates a new instance of the Till manager
   * then returns such instance in the form of a pointer
   * @return a pointer to the instance
   */
TillManager& TillManager::instance()
{
    if (_instance == NULL)
        _instance = new TillManager();
    return *_instance;
}

 /**
   * Till Manager destructor
   * When the Till manager is no longer required this destructs the instance and clears the items 
   */
TillManager:: ~TillManager(){
    this->tills.clear();
}

 /**
   * Till getter method
   * This returns the set of tills which are in the current Till
   * @return vector set of tills
   */
vector <Till> TillManager:: getTills(){
    return this->tills;
}

 /**
   * Till setter method
   * This clears the old Till then sets the current Till by adding new items passed in by parameter, 
   * one new at a time is added in a loop 
   * @param vector of new Till items
   */
void TillManager::setTills(vector <Till> tills){
    this->tills.clear();
	for (unsigned int i = 0; i < tills.size(); i++) {
        addTill(tills[i]);
    }
}
        
 /**
   * Print tills method
   * Takes the full list of all tills and for that size loops through sending each line to the other print 
   * tills where it does a job of printing off all information about the one object given to it 
   */
void TillManager::printAllTills(){
    cout<<endl<<"All tills listed:"<<endl<<endl;
    for (unsigned int i = 0; i < tills.size(); i++) {
        printTill(tills[i].getID());
    }
}  

 /**
   * Print detailed till method
   * For each item given to it, goes and searches through the list until it finds the first matching id
   * then prints out all attributes in relation to that item 
   * @param string Till item id
   */
void TillManager::printTill(string Id){
    cout<<endl;
    for (unsigned int i = 0; i < tills.size(); i++) {
        if(Id.compare(tills[i].getId()) ==0){
            cout<<"ID: "<<tills[i].getId()<<endl;
            cout<<"Till balance: "<<fixed<<setprecision(2)<<tills[i].getCashBalance()<<endl;
            return;
        }
    }
    cout<<"no till called " + Id + " found"<<endl; //! if it can not find the till then jsut prints it cant find it

}


 /**
   * Add new till method
   * Tries to add a till to the list of all tills, if the id already exists in the list then it 
   * comments saying you should remove the old one before adding a new till with the matching id.
   * @param Till object to be added to list of Tills
   */
void TillManager::addTill(Till till){
    for (unsigned int i = 0; i < tills.size(); i++) {
        if(till.getId().compare(tills[i].getId()) == 0){
            cout<<"the item with the name "+ item.getId()<<" already exists. Please delete it first."<<endl;
            return;
        }
    }

    if(till.getId().compare("-1")==0)
    {
            cout<<"the item was not valid and was not added to the system"<<endl;
    }else{
        tills.push_back(till);
        cout<<"the till with the ID "+ item.getId()<<" was added to the system."<<endl;
    }
}


 /**
   * Remove till (by id) method
   * This method tries to remove an till by matching the id from the list of tills, if the id does not exist
   * in the list then it comments saying that the till was not found
   * @param string id of till to remove
   */
void TillManager::removeTill(std::string Id){
    for (unsigned int i = 0; i < tills.size(); i++) {
        if(Id.compare(tills[i].getId()) ==0){
            tills.erase(tills.begin()+i);
            return;
        }
    }
    cout<<"The till with the id "+ Id<<" does not exists in the system. Could not remove it."<<endl;
}

 /**
   * Remove till (by till) method
   * This method tries to remove a till by extracting its id then calling the remove by id method 
   * @param Till object to remove
   */
void TillManager::removeTill(Till till){
    removeTill(till.getId());
}

 /**
   * Find till method
   * This method tries to locate a till by matching the id from the list of tills, if the id does not exist
   * in the list then it comments saying that the till was not found
   * @param string till id to find
   * @return Till object found from list of tills 
   */
Till * TillManager::findTill(string id){
    for (unsigned int i = 0; i < tills.size(); i++) {
        if(id.compare(tills[i].getId()) ==0){
            return &tills[i];
        }
    }
    cout<<"the till with the id "+ id <<" does not exists in the system."<<endl;
}
