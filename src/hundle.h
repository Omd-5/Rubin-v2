// function to extract a value from a string
int getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
  for (int i=0; i<=maxIndex && found<=index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1]+1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]).toInt() : 0;
}


bool 2of4(bool a, bool b, bool c, bool d){
  if (a && b){
    return true;
  }else if (a && c){
    return true;
  }else if (a && d){
    return true;
  }else if (b && c){
    return true;
  }else if (b && d){
    return true;
  }else if (c && d){
    return true;
  }else{
    return false;
  }
}

bool upThen(int B, int A){
  if (A > B){
    return true;
  }else{
    return false;
  }
}