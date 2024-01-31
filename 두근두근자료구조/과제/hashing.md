# Hashing 기반 데이터 저장 및 탐색 시스템

## Hash Function

## Hash Table

## Hash Table Initialization Function

## **Insertion Function based on Quadratic Probing**

1. 증복 확인
2. Overflow 발생 시, 해당 bucket 출력
3. Overflow 발생 시, 이차조사법
4. 해시 테이블 포화 상태 확인
5. 삽입

### 중복 확인

Hash table에서 해당 bucket의 slot key 값 중 입력 key 값과 동일한 값이 존재한다면, 중복임을 알리는 문구를 출력한다.

### Overflow 발생

Hash table에서 해당 bucket의 모든 slot의 key 값이 초기값(0)이 아니라면,

- 해당 bucket의 모든 slot을 출력한다.
- 이차 조사법에 의하여 인덱스를 바꾼다.

Hash table에서 해당 bucket의 모든 slot의 key 값이 초기값(0)이 아니다 == 해당 bucket에서 SLOT_SIZE 번째 slot의 key 값이 초기값(0)이 아니다

### Hash table saturation check

Hash table의 모든 slot의 key 값이 초기값(0)이 아니라면, 해시 테이블이 포화 상태임을 알리는 문구를 출력한다.

Hash table의 모든 slot의 key 값이 초기값(0)이 아니다 == 모든 bucket의 SLOT_SIZE 번째의 slot의 key 값이 초기값(0)이 아니다.

### 삽입

해당 bucket에서 비어있고 인덱스가 가장 작은 slot에 입력 key와 입력 value를 삽입한다.
