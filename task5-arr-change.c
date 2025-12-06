void arrChange(int i, int count, int arrayLength, int numArray[arrayLength], int resultNumArray[arrayLength]) {
    count = 1; /*fill result array of numbers with odd indices*/
    for (i = count; i < arrayLength; i = i + 2) {
        resultNumArray[i - count] = numArray[i];
        count++;
    }

    count = (arrayLength / 2); /*fill result array of numbers with even indices*/
    for (i = 0; i < arrayLength; i = i + 2) {
        resultNumArray[count] = numArray[i];
        count++;
    }
}