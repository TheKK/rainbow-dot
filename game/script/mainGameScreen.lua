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
	local x = startX
	local y = startY
	local frameCount = 0

	co = coroutine.create(
	function()
		while (1) do
			x, y, frameCount = path1(startX, startY, 1, 0, frameCount)
		end
	end
	)

	return co
end

function testEnemy2()
	local startX = 0
	local startY = 100
	local x = startX
	local y = startY
	local frameCount = 0

	co = coroutine.create(
	function()
		while (1) do
			x, y, frameCount = path2(startX, startY, x, y, frameCount)
		end
	end
	)
	return co
end

function path1(startX, startY, velX, velY, frameCount)
	local x = startX + (velX * frameCount)
	local y = startY + (velY * frameCount)
	coroutine.yield(x, y)

	frameCount = frameCount + 1

	return x, y, frameCount
end

function path2(startX, startY, x, y, frameCount)
	x = x + math.abs(math.sin(math.pi * frameCount / 30) * 3)
	y = startY + math.abs(math.sin(math.pi * frameCount / 30) * 6)
	coroutine.yield(x, y)

	frameCount = frameCount + 1

	return x, y, frameCount
end
