#!/bin/bash

# Script to clean up shell history and cache files on macOS
# Created: May 8, 2025

echo "Starting macOS history and cache cleanup..."

# Clear bash history
if [ -f ~/.bash_history ]; then
  echo "Removing .bash_history file..."
  rm ~/.bash_history
  touch ~/.bash_history
  echo ".bash_history cleared"
else
  echo ".bash_history not found"
fi

# Clear zsh history
if [ -f ~/.zsh_history ]; then
  echo "Removing .zsh_history file..."
  rm ~/.zsh_history
  touch ~/.zsh_history
  echo ".zsh_history cleared"
else
  echo ".zsh_history not found"
fi

# Clear application cache
echo "Clearing application caches..."
rm -rf ~/Library/Caches/*
echo "Application caches cleared"

# Clear Safari cache
if [ -d ~/Library/Safari ]; then
  echo "Clearing Safari cache..."
  rm -rf ~/Library/Safari/LocalStorage/*
  rm -rf ~/Library/Safari/Cache.db
  echo "Safari cache cleared"
fi

# Clear Chrome cache
if [ -d ~/Library/Application\ Support/Google/Chrome ]; then
  echo "Clearing Chrome cache..."
  rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Cache/*
  rm -rf ~/Library/Application\ Support/Google/Chrome/Default/Code\ Cache/*
  echo "Chrome cache cleared"
fi

# System cache and DNS cache clearing removed (required sudo)

echo "Cache cleanup complete!"
