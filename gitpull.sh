#!/bin/sh
NOW=$(date +"%c")
git add usr
git add bin
git add dev
git add etc
git add lib
git add lib64
git add root
git add run
git add sbin
git add var
git commit -a -m "$NOW"
git fetch origin https://luisbtejada:Volando1!@github.com/luisbtejada/test1.git
git pull origin https://luisbtejada:Volando1!@github.com/luisbtejada/test1.git
git push origin https://luisbtejada:Volando1!@github.com/luisbtejada/test1.git
