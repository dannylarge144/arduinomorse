char alph[37] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
String morse[37] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(1, OUTPUT);


}

String char2morse (char c) {
  c = toLowerCase(c);
  bool error = true;
  int x = 0;
  for (x = 0; x < 37; x++) {
    if (char(c) == char(alph[x])) {
      error = false;
      return morse[x];
      break;
    }
    else if (char(c) == '\0'){
      error = false;
    }
    }
  if (error) {
    return "........";
  }
}

String string2morse(String s) {
  int z = s.length();
  char sa[z];
  s.toCharArray(sa, z + 1);
  int y = 0;
  String finalresult = "";
  String w = "";
  for (y = 0; y < z; y++) {
    w = char2morse(sa[y]);
    bool error = false;
    finalresult += w + "/";
  }
  return finalresult;
}


void sendDigital (int pin, String message) {
  String r = string2morse(message);
  int b = r.length();
  int h = 0;
  for (h = 0; h < b; h++) {
    switch (r[h]) {
      case '.' :
        digitalWrite(pin, HIGH);
        delay(83);
        digitalWrite(pin, LOW);
        delay(83);
      case '-' :
        digitalWrite(pin, HIGH);
        delay(249);
        digitalWrite(pin, LOW);
        delay(83);
      case '/':
        delay(249);
      case ' ':
        delay(83);

    }

  }

}

char morse2char (String m) {
  int c = 0;
  char o = '?';
  for (c = 0; c < 37; c++) {
    if (m.equals (String(morse[c]))) {
      char o = alph[c];
      return alph[c];
      break;
    }
  }
  return o;
}

String duration2morse (int* durations, int len) {
  int p = 0;
  int l = abs(durations[p]);
  String finalresult = "";
  for (p = 0; p < len; p++) {
    if (abs(durations[p]) < l){
      l = abs(durations[p]);
      }
  }
  for (p = 0; p < len; p++) {
    if (durations[p] == l) {
      finalresult += '.';
      continue;
    }
    else if (durations[p] == (-1 * l)) {
      continue;
    }
    else if (durations[p] == (-3 * l)){
      finalresult += '/';
      continue;
    }
    else if (durations[p] == (3 * l)) {
      finalresult += '-';
      continue;
    }
    else if (durations[p] == (-7 * l)) {
      finalresult += "/ /";
      continue;
    }
    else {
      finalresult += "/......../";
      continue;
    }
  }

  return finalresult;
}


String morse2string (String u) {
  int f = 0;
  String b = "";
  String j = "";
  int s;
  int d = u.length();
  bool space = false;
  for (f = 0; f < d; f++) {
    switch (u[f]) {
      case '.' :
        j += '.';
        continue;
      case '-' :
        j += '-';
        continue;
      case ' ':
        j = " ";
        space = true;
        continue;
      case '/':
        if (! space){
          j.trim();
        }
        b += morse2char(j);
        j = "";
        space = false;
          continue;
          }
          continue;
        }
  b.trim();
  return b;



}

//String rir(){
  
//}

String readDigital (int b){
  bool buttonState = LOW;
  for (;;){
    int a = 0;
    while (buttonState == HIGH){
      
    }
    millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

while (! Serial.available()){
  ;
}
bool isplain = true;
String m = Serial.readString();
if(m[0] == '.' || m[0] == '-'){
  if(m1] == '.' || m[1] == '-'){
    Serial.println(morse2string(m));
    isplain = false;
  }
}
if (isplain){
  Serial.println(string2morse(m));
}

}
