#include "Map.h"

int Map::hash(string key)
{
  int sum = 0;

  for(int i=0;i < (int)key.length();i++)
    sum+=key[i];

  return sum;
}

Map::Map()
{
  for(int i=0;i<999999;i++)
  {
    array.push_back(new list< pair<string,int>* >);
  }
}

void Map::put(string key, int value)
{
  list< pair<string, int>* > * s =  array[hash(key)];
  s->push_back(new pair<string, int>(key, value));
}

int Map::get(string key)
{
  list< pair<string, int>* > * s =  array[hash(key)];

  for(list< pair<string, int>* >::iterator t = s->begin(); t != s->end(); t++)
  {
    pair<string, int>* current_pair = *t;
    if(current_pair->first == key)
      return current_pair->second;
  }

  return -1;
}

//Implementar Existe
bool Map::exists(string key)
{
  list< pair<string,int>* >* s = array[hash(key)];

  for(list< pair<string, int>* >::iterator t = s->begin(); t != s->end(); t++)
  {
    if((*t)->first == key) return true;
  }

  return false;
}

//Implementar la funcion remover o delete
void Map::remove(string key)
{
  list< pair<string, int>* >* s = array[hash(key)];

  for(list< pair<string, int>* >::iterator t = s->begin(); t != s->end(); t++)
  {
    pair<string, int>* element = *t;
    if(element->first == key)
    {
      s->erase(t);
      return;
    }
  }
}
