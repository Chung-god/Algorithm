
    for(int i = 1; i < N; i++){
        if(cfn[i].first >= result[j].second){
            result.push_back(cfn[i]);
            j++;
            cout<<cfn[i].first<<","<<cfn[i].second<<" ";
        } 
    }
    cout<<j+1;
}
