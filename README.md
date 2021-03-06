# Day For Night

## Contributing

This project requires **openFrameworks 0.9.0**. You can [download it from the oF website](http://openframeworks.cc/download/) if you don't already have it installed.

You'll also need to have your username added to the GitHub project, so have Zach add you if he hasn't already.

### 1. Find an artist to work with

Take a look at the [project wiki](https://github.com/ofZach/dayForNightSFPC/wiki) and find an artist you'd like to work with.


### 2. Checkout the project from GitHub

In you openFrameworks `apps` folder, create a new folder for the "Day for Night" project. Then `cd` into that folder using the terminal and checkout the project from GitHub:

```bash
git clone https://github.com/ofZach/dayForNightSFPC.git
```

### <del>3. Make a branch</del>

<del>It's probably a good idea to work in your own branch.</del> Actually, probably not totally necessary if you're making a sketch but feel free to do it if you want :).

Create a new branch:

```bash
cd dayForNightSFPC
git checkout -b branchName
```

### 4. Generate a new scene

Now you can use the scene generator script to generate a new scene. This will copy the `emptyScene` files and rename based on your new scene name.

Use the terminal to `cd` into your project folder and run the following, substituting `sceneName` with the name of your scene:

```bash
./generate_scene.sh sceneName
```

It will copy the following files and create new files for your new scene:

 * `bin/data/emptyScene/` => `bin/data/sceneName/`
 * `src/scenes/emptyScene/` => `src/scenes/sceneName/`

Now you you can drag the new folder in the `scenes` folder into XCode. Make sure to use these settings if you drag the folder in:

![XCode Settings](https://dl.dropboxusercontent.com/u/2100102/sfpc/xcode-drag-files.png)

### 5. Submitting Changes

There are two different workflows for submitting changes:

#### If you're adding a new scene and not changing the architecture

Check to make sure you don't have uncommitted changes (commit them if you do):

```bash
git status
```

Now checkout the master branch and make sure it's up to date:

```bash
git checkout master
git pull
```

Now merge in your branch:

```bash
git merge branchName
```

Now push your changes to the repo:

```bash
git push
```


#### If you're making architectural changes

It's probably better to push your branch instead of merging directly into `master`, then submit a pull request.

Check to make sure you don't have uncommitted changes in your branch (commit them if you do):

```bash
git status
```
Now push your branch to GitHub:

```bash
git push origin branchName
```

Now [go to the GitHub repo](https://github.com/ofZach/dayForNightSFPC) and submit a pull request via the GH interface.
