#고양이와 개는 몇 마리 있을까
SELECT ANIMAL_TYPE, COUNT(*)
FROM ANIMAL_INS
WHERE ANIMAL_TYPE = 'Cat' OR ANIMAL_TYPE = 'Dog' 
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE

#동명 동물 수 찾기
SELECT NAME,COUNT(*) 
FROM ANIMAL_INS
WHERE (NAME IS NOT NULL)
GROUP BY NAME
HAVING COUNT(*) > 1
ORDER BY NAME

#입양 시각 구하기(1)
SELECT HOUR(DATETIME), COUNT(*)
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) BETWEEN 9 AND 19
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)

#입양 시각 구하기(2)
SET @HOUR = -1;
SELECT (@HOUR := @HOUR + 1) AS HOUR , 
(SELECT COUNT(HOUR(DATETIME)) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @HOUR) AS COUNT 
FROM ANIMAL_OUTS
WHERE @HOUR < 23;
