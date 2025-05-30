cd %USERPROFILE%\OneDrive\Desktop
mkdir CSC2244 Marks Exam

mkdir practical theory "exam papers"

cd practical
echo. > practical.txt
echo. > practical.docx
echo. > practical.pptx

cd..
cd theory
echo. > theory.txt
echo. > theory.docx
echo. > theory.pptx

cd..
cd "exam papers"
echo. > "exam papers".txt
echo. > "exam papers".docx
echo. > "exam papers".pptx

cd..
cd %USERPROFILE%\OneDrive\Desktop
echo. > Icae_Marks.xlsx
echo. > Final_Exam_Marks.xlsx

move "C:\Users\pavan\OneDrive\Desktop\Icae_Marks.xlsx" "C:\Users\pavan\OneDrive\Desktop\Marks"
move "C:\Users\pavan\OneDrive\Desktop\Final_Exam_Marks.xlsx" "C:\Users\pavan\OneDrive\Desktop\Marks"

xcopy "C:\Users\pavan\OneDrive\Desktop\Marks" "C:\Users\pavan\OneDrive\Desktop\Exam" /E /I /H

attrib +h "C:\Users\pavan\OneDrive\Desktop\Exam"