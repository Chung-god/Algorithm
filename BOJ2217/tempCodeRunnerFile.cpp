int Sum = 0;

    for(int i = 0; i < rope.size(); i++){
        int temp = rope[i] *(i+1);
        cout<<temp<<" ";
        if(temp < Sum){
            cout<<Sum;
            return 0;
        }
        Sum = temp;
    }
    cout<<Sum;