    void Enqueue(int item){
        Push item INTO Stack1
    }

    bool QEmpty(void){
        IF Stack1 is Empty AND Stack2 is Empty THEN
            RETURN True;
        ELSE 
            RETURN FALSE
        END IF 
    }

    void Dequeue(void){
        IF QEmpty THEN
            DISPLAY "Empty Queue"
        ELSE
            IF Stack2 is Empty
                Transfer()
                Pop Stack2
            ELSE
                Pop Stack2
            END IF
        END IF
    }

    void Transfer(void){
        IF QEmpty THEN
            DISPLAY "Empty Queue"
        ELSE
            WHILE Stack1 is NOT Empty
                Push Stack1's Top INTO Stack2
                Pop Stack1
            END WHILE
        END IF
    }

    void Display(void){
        IF QEmpty THEN
            DISPLAY "Empty Queue"
        ELSE
            Transfer()
            Display Stack2
        END IF
    }