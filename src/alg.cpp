// Copyright 2021 NNTU-CS

int bs(int* arr, int l, int r, int value) {
  int mid = 0;
  bool f = 0;
  while (l <= r) {
    mid = (l + r) / 2;
    if (arr[mid] == value) {
      return bs(arr, l, mid - 1, value) + bs(arr, mid + 1, r, value) + 1;
    }
    if (value < arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
    }
  return 0;
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[j] + arr[i] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0, k = len - 1;
  while (arr[k] > value) {
    len--;
    k--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0, tmp, k = len - 1;
  while (arr[k] > value) {
    len--;
    k--;
  }
  for (int i = 0; i < len; i++) {
    tmp = value - arr[i];
    count += bs(arr + i + 1, 0, len - i, tmp);
  }
  return count;
}
