void Ada30002(){
    if(ECHO){
           Serial.print("sending -> ");
           Serial.print(minni.Data30002.npulse);  Serial.print(" ");  
           Serial.print(minni.Data30002.sPeriod);Serial.print(" ");  
           Serial.println();
    }   
           npulse->    save(minni.Data30002.npulse);
           sPeriod->    save(minni.Data30002.sPeriod);
}
/*
Pointers and members
Normally when you access a member of a class or struct you use ., such as Serial.println(). 
However it is possible to make a pointer to a class instance, 
and when you do you need to access the members with -> instead of . - such as mySerial->println(). 
This arrow notation serves as syntactic sugar: mySerial->println() is interpreted as 
(*mySerial).println(). 
The parentheses are necessary because the dereferencing operator * has a lower order 
of precedence compared to the dot . operator.
*/
