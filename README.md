# Philosophers – 42 Project

## 🌍 Table of Contents
- [🇫🇷 Français](#-français)
- [🇬🇧 English](#-english)

---

# 🇫🇷 Français

## 📖 Introduction
**Philosophers (philo)** est un projet de 42 qui introduit la **programmation concurrente** avec les **threads** et les **mutex**.  
L’objectif est de modéliser le problème des philosophes mangeant autour d’une table, en respectant les règles de synchronisation et d’accès aux ressources partagées.

---

## 🧩 Concepts importants
Avant de commencer le projet, il est essentiel de bien comprendre :  
- **Threads** : chaque philosophe correspond à un thread.  
- **Mutex** : chaque fourchette correspond à un mutex.  
- Synchronisation et gestion de l’accès aux ressources partagées.  

---

## 🔑 Points importants
- Bien réfléchir au cas **pair ou impair** du nombre de philosophes.  
- Ajouter des **`usleep`** entre les accès pour éviter les blocages.  
- Vérifier systématiquement les **lock/unlock** des mutex.  
- Utiliser un outil comme **philo visualizer** peut aider à mieux comprendre et déboguer le comportement du programme.  

---

# 🇬🇧 English

## 📖 Introduction
**Philosophers (philo)** is a 42 project that introduces **concurrent programming** with **threads** and **mutexes**.  
The goal is to model the dining philosophers problem, ensuring proper synchronization and access to shared resources.

---

## 🧩 Key Concepts
Before starting the project, it’s important to understand:  
- **Threads**: each philosopher is represented by a thread.  
- **Mutexes**: each fork is represented by a mutex.  
- Synchronization and safe access to shared resources.  

---

## 🔑 Important Points
- Carefully consider the case of an **even or odd** number of philosophers.  
- Add **`usleep` delays** between mutex actions to prevent deadlocks.  
- Always check correct **lock/unlock** usage of mutexes.  
- Tools like **philo visualizer** can help you better see and debug the project behavior.
