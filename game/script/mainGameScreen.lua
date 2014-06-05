--[[
   [
   [ Author: KK <thumbd03803@gmail.com>
   [
   [ mainGameScreen.lua
   [
   ]]

function testEnemy1()
	local startX = 0
	local startY = 30

	co = coroutine.create(
	function()
		while (true) do
			startX, startY = path1(startX, startY, 1,-1, 30)
			startX, startY = path1(startX, startY, 1, 1, 30)
		end
	end
	)

	return co
end

function path1(startX, startY, velX, velY, duration)
	local x, y
	local frameCount = 0

	while (duration > 0) do
		x = startX + (velX * frameCount)
		y = startY + (velY * frameCount)

		duration = duration - 1
		frameCount = frameCount + 1

		coroutine.yield(x, y)
	end

	return x, y
end

function testEnemy2()
	local startX = 0
	local startY = 100

	co = coroutine.create(
	function()
		while (true) do
			startX, startY = path2(startX, startY, 6000)
		end
	end
	)
	return co
end

function path2(startX, startY, duration)
	local x, y
	local frameCount = 0

	while (duration > 0) do
		x = startX + math.abs(math.sin(math.pi * duration / 30) * 3)
		y = startY + math.abs(math.sin(math.pi * frameCount / 30) * 6)

		duration = duration - 1
		frameCount = frameCount + 1

		coroutine.yield(x, y)
	end

	return x, y
end
